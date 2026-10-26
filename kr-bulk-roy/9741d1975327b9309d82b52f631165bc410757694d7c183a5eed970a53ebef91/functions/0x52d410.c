
undefined4 * FUN_0052d410(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int in_EAX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar4 = param_1;
  puVar5 = *(undefined4 **)(in_EAX + 4);
  if (*(char *)((int)puVar5[1] + 0x29) == '\0') {
    uVar1 = param_1[1];
    uVar2 = *param_1;
    puVar6 = (undefined4 *)puVar5[1];
    param_1 = puVar5;
    do {
      uVar3 = puVar6[5];
      if ((puVar6[4] == uVar2) && (uVar3 == uVar1)) {
        uVar3 = puVar4[3];
        if ((uVar3 <= (uint)puVar6[7]) && ((puVar6[7] != uVar3 || (puVar4[2] <= (uint)puVar6[6]))))
        goto LAB_0052d450;
LAB_0052d46f:
        puVar7 = (undefined4 *)puVar6[2];
      }
      else {
        if ((uVar3 <= uVar1) && ((uVar3 < uVar1 || ((uint)puVar6[4] < uVar2)))) goto LAB_0052d46f;
LAB_0052d450:
        puVar7 = (undefined4 *)*puVar6;
        param_1 = puVar6;
      }
      puVar5 = param_1;
      puVar6 = puVar7;
    } while (*(char *)((int)puVar7 + 0x29) == '\0');
  }
  return puVar5;
}

