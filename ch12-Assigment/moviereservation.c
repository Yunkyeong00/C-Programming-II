void cancelBooking(const char* loginID)
{
    FILE* fp = fopen("booking.txt", "r");
    if (!fp) {
        printf("booking.txt 파일을 열 수 없습니다.\n");
        return;
    }

    Booking arr[200];
    int total = 0;

    while (fscanf(fp, " %19[^|] | %9[^|] | %9[^|] | %14[^\n]",
        arr[total].cinema_code,
        arr[total].id,
        arr[total].seat_codes,
        arr[total].booking_date) == 4)
    {
        total++;
    }
    fclose(fp);

 
    int indexList[200];
    int idxCount = 0;

    printf("\n======= [%s]님 예매 내역 =======\n", loginID);

    for (int i = 0; i < total; i++)
    {
        if (strcmp(arr[i].id, loginID) == 0)
        {
            indexList[idxCount] = i;

            printf("%d) 상영관:%s | 좌석:%s | 날짜:%s\n",
                idxCount + 1,
                arr[i].cinema_code,
                arr[i].seat_codes,
                arr[i].booking_date);

            idxCount++;
        }
    }

    if (idxCount == 0) {
        printf("예매 내역이 없습니다.\n");
        return;
    }


    int choice;
    printf("취소할 번호 선택: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > idxCount) {
        printf("잘못된 번호입니다.\n");
        return;
    }

    int delIndex = indexList[choice - 1]; 
    Booking del = arr[delIndex];


    char seatFile[64];
    sprintf(seatFile, "seat_%s.txt", del.cinema_code); 

    Seat seatArr[200];
    int sCount = load_seats(seatArr, seatFile);

    for (int i = 0; i < sCount; i++)
    {
        if (strcmp(seatArr[i].seat_code, del.seat_codes) == 0)
        {
            seatArr[i].is_reserved = 0;  
            break;
        }
    }

    save_seats(seatFile, seatArr, sCount);


    int cCount = load_cinemas(cinemas);

    for (int i = 0; i < cCount; i++)
    {
        if (strcmp(cinemas[i].code, del.cinema_code) == 0)
        {
            cinemas[i].available_seats++;
            break;
        }
    }

    save_cinemas(cinemas, cCount);

   
    for (int i = delIndex; i < total - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    total--; 
    fp = fopen("booking.txt", "w");
    for (int i = 0; i < total; i++)
    {
        fprintf(fp, "%s | %s | %s | %s\n",
            arr[i].cinema_code,
            arr[i].id,
            arr[i].seat_codes,
            arr[i].booking_date);
    }
    fclose(fp);

    printf("\n[%s] 좌석 취소 완료!\n\n", del.seat_codes);
}
