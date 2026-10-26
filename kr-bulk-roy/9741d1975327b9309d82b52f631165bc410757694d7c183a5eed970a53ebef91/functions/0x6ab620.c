
/* WARNING: Removing unreachable block (ram,0x006ab637) */

int FUN_006ab620(undefined4 *param_1)

{
  undefined4 *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  int iVar4;
  ushort *puVar5;
  ushort *unaff_EDI;
  
  if (param_1[4] == 0) {
    return -1;
  }
  puVar1 = param_1;
  if (7 < (uint)param_1[5]) {
    puVar1 = (undefined4 *)*param_1;
  }
  puVar5 = (ushort *)((int)puVar1 + (param_1[4] + -1) * 2);
  do {
    if (*puVar5 == *unaff_EDI) {
      iVar4 = 1;
      puVar2 = puVar5;
      puVar3 = unaff_EDI;
      while (*puVar2 == *puVar3) {
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) goto LAB_006ab672;
      }
      if ((-(uint)(*puVar2 < *puVar3) & 0xfffffffe) == 0xffffffff) {
LAB_006ab672:
        if (7 < (uint)param_1[5]) {
          param_1 = (undefined4 *)*param_1;
        }
        return (int)puVar5 - (int)param_1 >> 1;
      }
    }
    puVar2 = (ushort *)FUN_004026d0();
    if (puVar5 == puVar2) {
      return -1;
    }
    puVar5 = puVar5 + -1;
  } while( true );
}

