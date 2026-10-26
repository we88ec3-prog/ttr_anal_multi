
void FUN_0062d7c0(int param_1,uint param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  void *_Dst;
  uint *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  void **ppvVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 *local_3c;
  uint *local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090cd18;
  uVar9 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  uVar11 = param_2 >> 0x10 & 0xff;
  puVar3 = *(undefined4 **)(param_1 + 0x120);
  local_3c = (undefined4 *)*puVar3;
  ppvVar7 = &local_14;
  puVar6 = local_3c;
  local_14 = ExceptionList;
  while (ExceptionList = ppvVar7, puVar6 != puVar3) {
    FUN_0062d9b0(puVar6 + 0x10);
    piVar1 = puVar6 + 0x10;
    local_c = 0;
    _Dst = (void *)*piVar1;
    puVar13 = puVar6;
    if (_Dst != (void *)puVar6[0x11]) {
      FID_conflict__memcpy(_Dst,(void *)puVar6[0x11],0);
      puVar6[0x11] = _Dst;
      puVar13 = local_3c;
    }
    puVar12 = local_28;
    for (iVar10 = local_24 - (int)local_28 >> 2; iVar10 != 0; iVar10 = iVar10 + -1) {
      if ((*puVar12 != (uVar11 << 0x10 | param_2 & 0xff)) &&
         (*puVar12 != ((param_2 & 0xff) << 0x10 | uVar11))) {
        puVar4 = (uint *)puVar6[0x11];
        if ((puVar12 < puVar4) && (puVar5 = (uint *)*piVar1, puVar5 <= puVar12)) {
          if (puVar4 == (uint *)puVar6[0x12]) {
            FUN_006d6240(uVar9);
          }
          puVar13 = local_3c;
          if ((undefined4 *)puVar6[0x11] != (undefined4 *)0x0) {
            *(undefined4 *)puVar6[0x11] =
                 *(undefined4 *)(*piVar1 + ((int)puVar12 - (int)puVar5 >> 2) * 4);
          }
        }
        else {
          if (puVar4 == (uint *)puVar6[0x12]) {
            FUN_006d6240(uVar9);
          }
          if ((uint *)puVar6[0x11] != (uint *)0x0) {
            *(uint *)puVar6[0x11] = *puVar12;
          }
        }
        puVar6[0x11] = puVar6[0x11] + 4;
      }
      puVar12 = puVar12 + 1;
    }
    if (*(char *)((int)puVar13 + 0x89) == '\0') {
      puVar6 = (undefined4 *)puVar13[2];
      if (*(char *)((int)puVar6 + 0x89) == '\0') {
        cVar2 = *(char *)((int)*puVar6 + 0x89);
        puVar13 = puVar6;
        puVar6 = (undefined4 *)*puVar6;
        while (local_3c = puVar13, cVar2 == '\0') {
          cVar2 = *(char *)((int)*puVar6 + 0x89);
          puVar13 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
        }
      }
      else {
        cVar2 = *(char *)((int)puVar13[1] + 0x89);
        puVar8 = (undefined4 *)puVar13[1];
        puVar6 = puVar13;
        while ((puVar13 = puVar8, local_3c = puVar13, cVar2 == '\0' &&
               (puVar6 == (undefined4 *)puVar13[2]))) {
          cVar2 = *(char *)((int)puVar13[1] + 0x89);
          puVar8 = (undefined4 *)puVar13[1];
          puVar6 = puVar13;
        }
      }
    }
    local_c = 0xffffffff;
    if (local_28 != (uint *)0x0) {
      FUN_0089120c(local_28);
    }
    local_28 = (uint *)0x0;
    local_24 = 0;
    ppvVar7 = ExceptionList;
    puVar6 = puVar13;
  }
  ExceptionList = local_14;
  return;
}

