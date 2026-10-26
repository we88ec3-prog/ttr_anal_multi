
void FUN_0070d750(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI < 0x101) {
    iVar1 = _iscntrl(unaff_EDI);
    if (iVar1 == 0) {
      uVar2 = FUN_006f7c30(*(undefined4 *)(unaff_ESI + 0x34),&DAT_00c41240);
    }
    else {
      uVar2 = FUN_006f7c30(*(undefined4 *)(unaff_ESI + 0x34),"char(%d)");
    }
  }
  else {
    uVar2 = *(undefined4 *)(&DAT_00c0babc + unaff_EDI * 4);
  }
  FUN_006f7c30(*(undefined4 *)(unaff_ESI + 0x34),"\'%s\' expected",uVar2);
                    /* WARNING: Subroutine does not return */
  FUN_006ff130();
}

