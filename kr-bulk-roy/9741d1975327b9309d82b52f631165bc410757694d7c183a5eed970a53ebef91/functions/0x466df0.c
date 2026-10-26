
uint FUN_00466df0(undefined4 *param_1,ushort *param_2,uint param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  uint in_EAX;
  ushort *puVar3;
  ushort *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  
  if ((param_3 != 0) || ((uint)param_1[4] < in_EAX)) {
    if ((in_EAX < (uint)param_1[4]) && (uVar5 = param_1[4] - in_EAX, param_3 <= uVar5)) {
      iVar8 = uVar5 + (1 - param_3);
      puVar6 = param_1;
      if (7 < (uint)param_1[5]) {
        puVar6 = (undefined4 *)*param_1;
      }
      puVar3 = (ushort *)((int)puVar6 + in_EAX * 2);
      for (; iVar8 != 0; iVar8 = iVar8 + (-1 - (iVar7 >> 1))) {
        puVar4 = puVar3;
        iVar7 = iVar8;
        while (*puVar4 != *param_2) {
          puVar4 = puVar4 + 1;
          iVar7 = iVar7 + -1;
          if (iVar7 == 0) goto LAB_00466e4b;
        }
        puVar1 = puVar4;
        puVar2 = param_2;
        uVar5 = param_3;
        if (puVar4 == (ushort *)0x0) break;
        while( true ) {
          if (uVar5 == 0) goto LAB_00466e74;
          if (*puVar1 != *puVar2) break;
          puVar1 = puVar1 + 1;
          puVar2 = puVar2 + 1;
          uVar5 = uVar5 - 1;
        }
        if ((-(uint)(*puVar1 < *puVar2) & 0xfffffffe) == 0xffffffff) {
LAB_00466e74:
          if (7 < (uint)param_1[5]) {
            param_1 = (undefined4 *)*param_1;
          }
          return (int)puVar4 - (int)param_1 >> 1;
        }
        iVar7 = (int)puVar4 - (int)puVar3;
        puVar3 = puVar4 + 1;
      }
    }
LAB_00466e4b:
    in_EAX = 0xffffffff;
  }
  return in_EAX;
}

