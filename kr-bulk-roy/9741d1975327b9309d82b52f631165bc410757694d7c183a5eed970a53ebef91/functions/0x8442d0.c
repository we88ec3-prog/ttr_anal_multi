
undefined4
FUN_008442d0(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar6;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x68 + param_1 * 0x10);
  puVar3 = (undefined4 *)*puVar2;
  iVar6 = 0;
  while( true ) {
    if (puVar3 == puVar2) {
      return 0;
    }
    if (iVar6 == param_2) break;
    iVar6 = iVar6 + 1;
    if (*(char *)((int)puVar3 + 0x19) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x19) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x19);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x19);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x19);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x19);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  *param_3 = puVar3[3];
  *param_4 = puVar3[4];
  *param_5 = puVar3[5];
  return 1;
}

