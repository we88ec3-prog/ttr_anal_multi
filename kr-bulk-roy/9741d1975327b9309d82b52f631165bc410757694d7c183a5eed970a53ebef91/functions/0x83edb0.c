
undefined4 FUN_0083edb0(int *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_EAX;
  undefined4 *puVar5;
  uint uVar6;
  uint unaff_EDI;
  
  puVar2 = *(undefined4 **)(in_EAX + 4);
  puVar5 = (undefined4 *)*puVar2;
  for (uVar6 = 0; (puVar5 != puVar2 && (uVar6 < unaff_EDI)); uVar6 = uVar6 + 1) {
    if (*(char *)((int)puVar5 + 0x2d) == '\0') {
      puVar3 = (undefined4 *)puVar5[2];
      if (*(char *)((int)puVar3 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x2d);
        puVar5 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x2d);
          puVar5 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar5[1] + 0x2d);
        puVar4 = (undefined4 *)puVar5[1];
        puVar3 = puVar5;
        while ((puVar5 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar5[2]))) {
          cVar1 = *(char *)((int)puVar5[1] + 0x2d);
          puVar4 = (undefined4 *)puVar5[1];
          puVar3 = puVar5;
        }
      }
    }
  }
  if (puVar5 != puVar2) {
    *param_1 = (int)(puVar5 + 3);
    *param_2 = puVar5[10];
    return 1;
  }
  return 0;
}

