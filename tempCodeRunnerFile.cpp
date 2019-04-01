    if (input.is_open())
    {
        for (int i = 0; i < 6; i++){
            int tc;
            input >> tc;
            vSize[i] = tc;
            makeVector(vv[i], tc);
        }
        printData();
    }