
void FUN_008eb600(undefined4 param_1,uint param_2)

{
  int iVar1;
  int in_ECX;
  int unaff_ESI;
  ushort local_18;
  ushort local_16;
  short local_14;
  short local_12;
  ushort local_10;
  short local_e;
  short local_c;
  ushort local_a;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(unaff_ESI + 4);
  iVar1 = (**(code **)(*(int *)(iVar1 + 0x214) + 0x48))
                    (iVar1,*(undefined4 *)(in_ECX + 0x70),param_1,param_2,
                     *(undefined4 *)(iVar1 + 0x68),unaff_ESI + 0x4c,&local_18);
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_ESI + 0x6c) = 0;
    *(uint *)(unaff_ESI + 0x1c) = (uint)local_18 << 6;
    *(uint *)(unaff_ESI + 0x18) = (uint)local_16 << 6;
    *(int *)(unaff_ESI + 0x20) = (int)local_14 << 6;
    *(int *)(unaff_ESI + 0x24) = (int)local_12 << 6;
    *(uint *)(unaff_ESI + 0x28) = (uint)local_10 << 6;
    *(int *)(unaff_ESI + 0x2c) = (int)local_e << 6;
    *(int *)(unaff_ESI + 0x30) = (int)local_c << 6;
    *(uint *)(unaff_ESI + 0x34) = (uint)local_a << 6;
    *(undefined4 *)(unaff_ESI + 0x48) = 0x62697473;
    if ((param_2 & 0x10) != 0) {
      *(int *)(unaff_ESI + 100) = (int)local_e;
      *(int *)(unaff_ESI + 0x68) = (int)local_c;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    *(int *)(unaff_ESI + 100) = (int)local_14;
    *(int *)(unaff_ESI + 0x68) = (int)local_12;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

