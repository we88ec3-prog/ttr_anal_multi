
void FUN_008e9120(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  int local_18 [3];
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = *(int *)(unaff_ESI + 4);
  piVar1 = *(int **)(*(int *)(iVar2 + 0x80) + 0x30);
  *(undefined4 *)(unaff_ESI + 0x560) = *(undefined4 *)(iVar2 + 0x1b4);
  *(undefined4 *)(unaff_ESI + 0x564) = *(undefined4 *)(iVar2 + 0x1b8);
  *(undefined4 *)(unaff_ESI + 0x568) = *(undefined4 *)(iVar2 + 0x1bc);
  *(undefined4 *)(unaff_ESI + 0x56c) = *(undefined4 *)(iVar2 + 0x1c0);
  *(undefined4 *)(unaff_ESI + 0x570) = *(undefined4 *)(iVar2 + 0x1c4);
  *(undefined4 *)(unaff_ESI + 0x574) = *(undefined4 *)(iVar2 + 0x1c8);
  if (piVar1 == (int *)0x0) {
    *unaff_EBX = *(undefined4 *)(*(int *)(iVar2 + 0x1a8) + in_ECX * 4);
    unaff_EBX[1] = *(undefined4 *)(*(int *)(iVar2 + 0x1ac) + in_ECX * 4);
  }
  else {
    iVar2 = (**(code **)*piVar1)(piVar1[1]);
    if (iVar2 != 0) goto LAB_008e9230;
  }
  iVar2 = (**(code **)(unaff_ESI + 0x5cc))();
  if (((iVar2 == 0) && (piVar1 != (int *)0x0)) && (*(int *)(*piVar1 + 8) != 0)) {
    local_18[0] = FUN_008b7c80(*(undefined4 *)(unaff_ESI + 0x20));
    local_18[0] = local_18[0] >> 0x10;
    local_18[1] = 0;
    local_18[2] = FUN_008b7c80(*(undefined4 *)(unaff_ESI + 0x28));
    local_18[2] = local_18[2] >> 0x10;
    local_c = FUN_008b7c80(*(undefined4 *)(unaff_ESI + 0x2c));
    local_c = local_c >> 0x10;
    (**(code **)(*piVar1 + 8))(piVar1[1],in_ECX,0,local_18);
    *(int *)(unaff_ESI + 0x20) = local_18[0] << 0x10;
    *(int *)(unaff_ESI + 0x28) = local_18[2] << 0x10;
    *(int *)(unaff_ESI + 0x2c) = local_c << 0x10;
  }
LAB_008e9230:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

