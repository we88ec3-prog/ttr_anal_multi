
void FUN_00443380(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_ESI;
  int unaff_EDI;
  undefined4 local_30;
  int local_2c;
  void *pvStack_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009201bc;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
  iVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_004433e8;
    iVar2 = FUN_00745c20();
  }
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) &&
      ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar2 + 0x60) != 0)) {
    FUN_0074a010(iVar2);
  }
LAB_004433e8:
  if ((DAT_00fb7bcc & 1) == 0) {
    DAT_00fb7bcc = DAT_00fb7bcc | 1;
    local_c = 0;
    FUN_00820290();
    _atexit((_func_4879 *)&LAB_00bcd520);
    local_c = 0xffffffff;
  }
  uVar1 = *DAT_00fb7bf0;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 1;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_c = 0xffffffff;
  }
  local_30 = uVar1;
  FUN_008438c0(&local_30);
  if (local_2c == DAT_00f8d91c) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(local_2c + 0x10);
  }
  (**(code **)(**(int **)(in_ECX + 0x148) + 0x19c))
            (*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x1c),0,0);
  (**(code **)(**(int **)(in_ECX + 0x148) + 200))();
  FUN_004421b0(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0xf4) + 0xd0))();
  if ((*(int *)(in_ECX + 0xf4) != 0) && ((*(uint *)(*(int *)(in_ECX + 0xf4) + 0x28) >> 8 & 1) != 0))
  {
    FUN_00443da0();
    FUN_00749970((*(int *)(*(int *)(in_ECX + 0xf4) + 0x2c) -
                 *(int *)(*(int *)(in_ECX + 0xf4) + 0x34)) + unaff_EDI,unaff_ESI);
    FUN_004418a0();
  }
  ExceptionList = pvStack_24;
  return;
}

