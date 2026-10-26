
/* WARNING: Removing unreachable block (ram,0x0086d6f3) */
/* WARNING: Removing unreachable block (ram,0x0086d8c7) */
/* WARNING: Removing unreachable block (ram,0x0086d8ea) */
/* WARNING: Removing unreachable block (ram,0x0086d8ec) */
/* WARNING: Removing unreachable block (ram,0x0086d922) */
/* WARNING: Removing unreachable block (ram,0x0086d92e) */
/* WARNING: Removing unreachable block (ram,0x0086d937) */

void FUN_0086d600(undefined1 *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  int *in_EDX;
  int local_6c;
  uint local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009138f8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_8 = 0;
  if (*(int *)(in_ECX + 0x2c) == 0) {
    if (*(int *)(in_ECX + 0xc) != *(int *)(in_ECX + 0x10)) {
      FUN_00403040();
      goto LAB_0086d846;
    }
  }
  else {
    iVar2 = (**(code **)(*in_EDX + 0x24))();
    if (iVar2 == 0) {
      FUN_00403040();
    }
    else {
      (**(code **)(*in_EDX + 0x10))();
      if (local_6c == 1) {
        (**(code **)(*in_EDX + 0x5c))();
        if ((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x1c == 2) {
          FUN_00403040();
        }
        else {
          FUN_00402a70();
        }
      }
      else if (local_6c == 2) {
        (**(code **)(*in_EDX + 0x6c))();
        if ((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x1c == 0) {
          FUN_0043ff70();
        }
        else {
          FUN_00403040();
        }
      }
      else if (local_6c == 3) {
        (**(code **)(*in_EDX + 0x7c))();
        iVar2 = (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x1c;
        fVar1 = (float)iVar2;
        if (iVar2 < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        if (0.0 < fVar1) {
          FUN_00403040();
        }
      }
    }
LAB_0086d846:
    if (local_20 != 0) {
      if (*param_2 != -1) {
        FUN_00403040(local_30,0,0xffffffff);
        FUN_00872480();
        *param_2 = 0;
      }
      *(undefined4 *)(param_1 + 0x14) = 0xf;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *param_1 = 0;
      FUN_00402bb0();
      goto joined_r0x0086d971;
    }
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *param_1 = 0;
  FUN_00402bb0();
joined_r0x0086d971:
  if (0xf < local_1c) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

