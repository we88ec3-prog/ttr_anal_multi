
int FUN_0049ebe0(void)

{
  LPCSTR name;
  BOOL BVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_EDI;
  uint local_8;
  
  iVar5 = *unaff_EDI;
  iVar4 = 0;
  local_8 = 0;
  iVar3 = 0;
  if ((unaff_EDI[1] - iVar5) / 0x1c != 0) {
    do {
      name = (LPCSTR)(iVar4 + iVar5);
      if (0xf < *(uint *)(name + 0x14)) {
        name = *(LPCSTR *)name;
      }
      BVar1 = RemoveFontResourceExA(name,0x10,(PVOID)0x0);
      if (BVar1 == 0) {
        puVar2 = (undefined4 *)(*unaff_EDI + iVar4);
        if (0xf < (uint)puVar2[5]) {
          puVar2 = (undefined4 *)*puVar2;
        }
        FUN_006edd00(&DAT_00c060a0,puVar2);
      }
      iVar5 = *unaff_EDI;
      local_8 = local_8 + 1;
      iVar3 = (unaff_EDI[1] - iVar5) * -0x6db6db6d;
      iVar4 = iVar4 + 0x1c;
    } while (local_8 < (uint)((unaff_EDI[1] - iVar5) / 0x1c));
  }
  return iVar3;
}

