
uint FUN_0049eb20(void)

{
  LPCSTR name;
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *unaff_ESI;
  int local_8;
  
  FUN_0049e8b0();
  FUN_006edd00("Found %d font(s)",(unaff_ESI[1] - *unaff_ESI) / 0x1c);
  iVar1 = *unaff_ESI;
  iVar4 = unaff_ESI[1] - iVar1;
  uVar3 = iVar4 * -0x6db6db6d;
  uVar5 = 0;
  if (iVar4 / 0x1c + (iVar4 >> 0x1f) != iVar4 >> 0x1f) {
    local_8 = 0;
    do {
      name = (LPCSTR)(local_8 + iVar1);
      if (0xf < *(uint *)(name + 0x14)) {
        name = *(LPCSTR *)name;
      }
      iVar1 = AddFontResourceExA(name,0x10,(PVOID)0x0);
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)(*unaff_ESI + local_8);
        if (0xf < (uint)puVar2[5]) {
          puVar2 = (undefined4 *)*puVar2;
        }
        FUN_006edd00(&DAT_00c0607c,puVar2);
      }
      iVar1 = *unaff_ESI;
      local_8 = local_8 + 0x1c;
      uVar3 = (unaff_ESI[1] - iVar1) / 0x1c;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar3);
  }
  return uVar3;
}

