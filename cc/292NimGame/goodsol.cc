

public boolean canWinNim(int n) {
    return canWinNim(n, 0);
}

public boolean canWinNim(int n, int roundCount) {
    roundCount++;
    if (n <= 0) {
        return false;
    } else if (0 < n && n <= 3) { // 0~3 进行到奇数轮能赢
        return (roundCount % 2 == 1);
    }

    if (roundCount % 2 == 0) { // 偶数轮，拿1,2,3同时能赢才能赢
        return (canWinNim(n-1, roundCount) 
                && canWinNim(n-2, roundCount) 
                && canWinNim(n-3, roundCount));
    } else { // 奇数轮，拿任意一个能赢就能赢
        return (canWinNim(n-1, roundCount) 
                || canWinNim(n-2, roundCount) 
                || canWinNim(n-3, roundCount));
    }
}
