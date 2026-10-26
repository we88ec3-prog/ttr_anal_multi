
void FUN_006f41d0(void)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_108;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_108._0_1_ = 0;
  _memset((void *)((int)&local_108 + 1),0,0xff);
  if (*(int *)(in_ECX + 0x14) != 0) {
    iVar4 = *(int *)(in_ECX + 0x14);
    do {
      piVar2 = (int *)FUN_00542210();
      if ((int *)*piVar2 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)*piVar2;
      }
      uVar3 = (uint)piVar2[2] >> 4;
      if (*(uint *)(iVar5 + 8) <= uVar3) {
        uVar3 = uVar3 - *(uint *)(iVar5 + 8);
      }
      bVar1 = *(byte *)((piVar2[2] & 0xfU) + *(int *)(*(int *)(iVar5 + 4) + uVar3 * 4));
      if (iVar4 != 0) {
        *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
        if ((uint)(*(int *)(in_ECX + 0xc) << 4) <= *(uint *)(in_ECX + 0x10)) {
          *(undefined4 *)(in_ECX + 0x10) = 0;
        }
        iVar4 = iVar4 + -1;
        *(int *)(in_ECX + 0x14) = iVar4;
        if (iVar4 == 0) {
          *(undefined4 *)(in_ECX + 0x10) = 0;
        }
      }
      *(undefined1 *)((int)&local_108 + (uint)bVar1) = 0x80;
    } while (*(int *)(in_ECX + 0x14) != 0);
  }
  puVar6 = &local_108;
  puVar7 = (undefined4 *)(in_ECX + 0x1c);
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

