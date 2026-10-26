
int FUN_008cce70(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *unaff_EBX;
  int iVar5;
  
  iVar3 = 0;
  iVar2 = *unaff_EBX + -1;
  do {
    do {
      if (iVar2 < 1) {
        return iVar3;
      }
      iVar5 = iVar2 + -1;
      bVar1 = iVar2 < 1;
      iVar2 = iVar5;
    } while (bVar1);
    do {
      iVar4 = FUN_008cccf0();
      if (iVar4 != 0) {
        iVar3 = FUN_008ccd50();
        if (iVar3 != 0) {
          return iVar3;
        }
        break;
      }
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
  } while( true );
}

