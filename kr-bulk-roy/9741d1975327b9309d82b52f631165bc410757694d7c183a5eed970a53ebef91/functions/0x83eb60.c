
undefined4 FUN_0083eb60(int *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_EAX;
  undefined4 *puVar6;
  uint uVar7;
  uint unaff_EDI;
  
  puVar2 = *(undefined4 **)(in_EAX + 4);
  puVar6 = (undefined4 *)*puVar2;
  for (uVar7 = 0; (puVar6 != puVar2 && (uVar7 < unaff_EDI)); uVar7 = uVar7 + 1) {
    if (*(char *)((int)puVar6 + 0x2d) == '\0') {
      puVar3 = (undefined4 *)puVar6[2];
      if (*(char *)((int)puVar3 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x2d);
        puVar6 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x2d);
          puVar6 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar6[1] + 0x2d);
        puVar5 = (undefined4 *)puVar6[1];
        puVar3 = puVar6;
        while ((puVar6 = puVar5, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar6[2]))) {
          cVar1 = *(char *)((int)puVar6[1] + 0x2d);
          puVar5 = (undefined4 *)puVar6[1];
          puVar3 = puVar6;
        }
      }
    }
  }
  if (puVar6 != puVar2) {
    uVar4 = puVar6[10];
    *param_1 = (int)(puVar6 + 3);
    *param_2 = uVar4;
    return 1;
  }
  return 0;
}

