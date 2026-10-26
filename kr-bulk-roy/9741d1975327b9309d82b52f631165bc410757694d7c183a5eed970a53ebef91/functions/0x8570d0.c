
undefined4 FUN_008570d0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_EAX;
  
  puVar2 = (undefined4 *)**(undefined4 **)(in_EAX + 4);
  while( true ) {
    if (puVar2 == *(undefined4 **)(in_EAX + 4)) {
      return 0;
    }
    if ((puVar2[3] == 0) && (puVar2[5] == 0)) break;
    if (*(char *)((int)puVar2 + 0x21) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x21);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x21);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x21);
        puVar5 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar5, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x21);
          puVar5 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  *param_2 = puVar2[6];
  uVar4 = puVar2[7];
  *param_1 = puVar2[4];
  *param_3 = uVar4;
  return 1;
}

