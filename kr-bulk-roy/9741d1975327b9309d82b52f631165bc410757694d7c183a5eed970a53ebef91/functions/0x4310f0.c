
void FUN_004310f0(void)

{
  undefined4 *puVar1;
  _Locimp *p_Var2;
  int unaff_ESI;
  _Lockit local_c [4];
  int local_8;
  
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0x201;
  *(undefined4 *)(unaff_ESI + 0x18) = 6;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0;
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  FUN_00431a90(0);
  puVar1 = (undefined4 *)FUN_00891268(4);
  if (puVar1 != (undefined4 *)0x0) {
    p_Var2 = std::locale::_Init();
    *puVar1 = p_Var2;
    local_8 = FUN_0087ded7();
    std::_Lockit::_Lockit(local_c,0);
    if (*(int *)(local_8 + 4) != -1) {
      *(int *)(local_8 + 4) = *(int *)(local_8 + 4) + 1;
    }
    FUN_0087dd6f();
    *(undefined4 **)(unaff_ESI + 0x30) = puVar1;
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  return;
}

