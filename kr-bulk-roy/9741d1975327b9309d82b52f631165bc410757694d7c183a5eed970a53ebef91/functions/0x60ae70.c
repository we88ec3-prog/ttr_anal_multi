
void FUN_0060ae70(void)

{
  uint uVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int unaff_EDI;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009126bf;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined1 *)(unaff_EDI + 0x118) = 0;
  if (*(char *)(*(int *)(unaff_EDI + 0xf8) + 0x141) != '\0') {
    FUN_006edb10("Not supported operation",uVar1);
  }
  iVar4 = 0;
  iVar2 = FUN_0044df20(0,&DAT_00bed1fc,0);
  if (iVar2 != 0) {
    (**(code **)(**(int **)(unaff_EDI + 0xfc) + 0x90))(1);
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  local_14 = *(int *)(unaff_EDI + 0x110);
  FUN_008438c0(&local_14);
  if (local_18 != DAT_00f8d91c) {
    iVar4 = *(int *)(local_18 + 0x10);
  }
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 1;
    FUN_00523540();
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
    local_8 = 0xffffffff;
  }
  local_18 = *(int *)(iVar4 + 0x20);
  FUN_008438c0(&local_18);
  if ((local_14 != DAT_00f8d9b0) && (*(int *)(local_14 + 0x10) != 0)) {
    if ((DAT_00fb744c & 1) == 0) {
      DAT_00fb744c = DAT_00fb744c | 1;
      local_8 = 3;
      FUN_004eec60();
      _atexit(FUN_00bcd140);
      local_8 = 0xffffffff;
    }
    psVar3 = (short *)FUN_004eeb00();
    if ((psVar3 != (short *)0x0) && (psVar3[1] != *psVar3)) {
      (**(code **)(**(int **)(unaff_EDI + 0xfc) + 0x90))(0);
      *(undefined1 *)(unaff_EDI + 0x118) = 1;
    }
  }
  ExceptionList = local_10;
  return;
}

