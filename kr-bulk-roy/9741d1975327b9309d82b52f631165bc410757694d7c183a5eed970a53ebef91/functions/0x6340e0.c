
void FUN_006340e0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int unaff_EDI;
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00948c54;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 0;
    FUN_004ffe60(uVar1);
    _atexit((_func_4879 *)&LAB_00bccf00);
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_00500fd0(&DAT_00fab2a0);
  uVar2 = uVar2 & 0xffff;
  local_24 = uVar2;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 1;
    FUN_004ffe60(uVar1);
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
  }
  local_14 = FUN_005013a0(&DAT_00fab2a0);
  local_14 = local_14 & 0xffff;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 2;
    FUN_004ffe60(uVar1);
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
  }
  iVar3 = DAT_00fb114c;
  local_1c = uVar2;
  FUN_00503d20(&local_1c);
  if (local_18 == *(int *)(iVar3 + 4)) {
    local_18 = 0;
  }
  else {
    local_18 = local_18 + 0x10;
  }
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 3;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
    iVar3 = DAT_00fb114c;
  }
  local_1c = local_14;
  FUN_00503d20(&local_1c);
  if (local_20 == *(int *)(iVar3 + 4)) {
    local_1c = 0;
  }
  else {
    local_1c = local_20 + 0x10;
  }
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 4;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
  }
  local_24 = local_24 & 0xffff;
  FUN_00503cb0(&local_24);
  if (local_20 == DAT_00fb119c) {
    iVar3 = 0;
  }
  else {
    iVar3 = local_20 + 0x10;
  }
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 5;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_8 = 0xffffffff;
  }
  local_24 = local_14 & 0xffff;
  FUN_00503cb0(&local_24);
  if (local_20 == DAT_00fb119c) {
    local_20 = 0;
  }
  else {
    local_20 = local_20 + 0x10;
  }
  if ((local_18 == 0) || (iVar3 == 0)) {
    if ((local_1c == 0) || (local_20 == 0)) {
      FUN_00757710();
      FUN_00765f70(*(undefined4 *)(unaff_EDI + 0xfc),&DAT_00bed1fc);
      (**(code **)(**(int **)(unaff_EDI + 0x100) + 0x94))(0);
      (**(code **)(**(int **)(unaff_EDI + 0x104) + 0x94))(0);
      (**(code **)(**(int **)(unaff_EDI + 0x108) + 0x94))(0);
      (**(code **)(**(int **)(unaff_EDI + 0x10c) + 0x94))(0);
      (**(code **)(**(int **)(unaff_EDI + 0x110) + 0x94))(0);
    }
    else {
      FUN_00634740(unaff_EDI,local_20,1);
    }
  }
  else {
    FUN_00634740(unaff_EDI,iVar3,0);
  }
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0xfc) + 200))();
  ExceptionList = local_10;
  return;
}

