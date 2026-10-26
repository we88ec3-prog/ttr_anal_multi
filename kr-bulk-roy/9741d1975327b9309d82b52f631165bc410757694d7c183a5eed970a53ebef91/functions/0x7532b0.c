
void FUN_007532b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int in_EDX;
  int *unaff_EBX;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58 [15];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092be0a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  local_5c = param_2;
  local_64 = in_EDX;
  FUN_0082ef00(&local_64);
  if ((((local_58[0] != *(int *)(param_1 + 0x1414)) && (*(int **)(local_58[0] + 0x10) != (int *)0x0)
       ) && (*(int *)(param_1 + 0x13c4) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(local_58[0] + 0x10) + 0x28))(uVar1), local_64 = iVar2,
     iVar2 != 0)) {
    FUN_0074a200();
    (**(code **)(**(int **)(param_1 + 0x13c4) + 0x70))(iVar2);
    if (*(int *)(iVar2 + 0x80) != 0) {
      *(undefined4 *)(*(int *)(iVar2 + 0x80) + 0xd4) = param_3;
    }
    FUN_00757710();
    FUN_007572f0(local_60);
    puStack_10 = (undefined1 *)0x0;
    if ((unaff_EBX[0x20] != 0) && (iVar2 = *(int *)(unaff_EBX[0x20] + 0xcc), iVar2 != 0)) {
      FUN_00405300(iVar2 + 0xe8);
    }
    puStack_10 = (undefined1 *)0xffffffff;
    FUN_00757640(local_58);
    if (unaff_EBX[0x20] != 0) {
      *(undefined4 *)(unaff_EBX[0x20] + 0xd0) = param_4;
    }
    (**(code **)(*unaff_EBX + 0xd0))();
    (**(code **)(*unaff_EBX + 200))();
    *(int **)(param_1 + 0x13dc) = unaff_EBX;
    *(undefined1 *)(param_1 + 0x13d9) = 1;
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_64);
  return;
}

