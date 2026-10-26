
void FUN_008e17e0(int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  int *unaff_EDI;
  char local_2d;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_14;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_2d = '\0';
  if (*(int *)(in_ECX + 0x2de4) == 2) {
    piVar2 = (int *)(in_ECX + 0x2df0);
  }
  else {
    piVar2 = (int *)(in_ECX + 0x2e00);
  }
  if (((*piVar2 != *unaff_EDI) || (piVar2[1] != unaff_EDI[1])) &&
     (local_2d = FUN_008e1570(), local_2d != '\0')) {
    *piVar2 = 0;
    piVar2[1] = 0;
  }
  local_2c = *(int *)(in_ECX + 0x2dd0);
  local_28 = *(int *)(in_ECX + 0x2dd4);
  if (*(int *)(in_ECX + 0x2de4) == 2) {
    local_c = 2;
    iVar1 = in_ECX + 0xf24;
    if (param_4 == '\0') {
      iVar1 = param_1;
    }
    FUN_008e1420(iVar1,*(undefined4 *)(in_ECX + 0x2df0),*(undefined4 *)(in_ECX + 0x2df4));
    if ((local_2c != local_24) || (local_28 != local_20)) {
      (**(code **)(*(int *)(in_ECX + 4) + 4))(*(int *)(in_ECX + 4),&local_2c);
      local_14 = local_24;
      local_10 = local_20;
      goto LAB_008e1944;
    }
  }
  else if (*(int *)(in_ECX + 0x2de4) == 4) {
    local_c = 4;
    FUN_008e1420(param_1,*(undefined4 *)(in_ECX + 0x2df0),*(undefined4 *)(in_ECX + 0x2df4));
    FUN_008e1420(param_1,*(undefined4 *)(in_ECX + 0x2df8),*(undefined4 *)(in_ECX + 0x2dfc));
    FUN_008e1420(param_1,*(undefined4 *)(in_ECX + 0x2e00),*(undefined4 *)(in_ECX + 0x2e04));
    (**(code **)(*(int *)(in_ECX + 4) + 0xc))(*(int *)(in_ECX + 4),&local_2c);
LAB_008e1944:
    *(int *)(in_ECX + 0x2dd4) = local_10;
    *(int *)(in_ECX + 0x2dd0) = local_14;
  }
  if (local_2d == '\0') {
    if (param_4 != '\0') {
      param_1 = in_ECX + 0xf24;
    }
  }
  else {
    if (param_4 == '\0') goto LAB_008e19d9;
    param_1 = in_ECX + 0xf24;
  }
  FUN_008e1420(param_1,*unaff_EDI,unaff_EDI[1]);
  if ((local_24 != *(int *)(in_ECX + 0x2dd0)) || (local_20 != *(int *)(in_ECX + 0x2dd4))) {
    local_28 = *(int *)(in_ECX + 0x2dd4);
    local_2c = *(int *)(in_ECX + 0x2dd0);
    local_c = 2;
    (**(code **)(*(int *)(in_ECX + 4) + 4))(*(int *)(in_ECX + 4),&local_2c);
    *(int *)(in_ECX + 0x2dd0) = local_24;
    *(int *)(in_ECX + 0x2dd4) = local_20;
  }
LAB_008e19d9:
  if (local_2d != '\0') {
    *unaff_EDI = 0;
    unaff_EDI[1] = 0;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

