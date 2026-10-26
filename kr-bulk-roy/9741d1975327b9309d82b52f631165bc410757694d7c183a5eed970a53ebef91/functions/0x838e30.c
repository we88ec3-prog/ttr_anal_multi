
undefined4 FUN_00838e30(ushort *param_1)

{
  undefined4 *puVar1;
  ushort *puVar2;
  int in_EAX;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar2 = param_1;
  puVar4 = *(undefined4 **)(in_EAX + 0x1c);
  piVar3 = (int *)FUN_0083fcb0(&param_1,*(undefined4 *)(in_EAX + 0x18),puVar4);
  puVar5 = (undefined4 *)*piVar3;
  if (puVar5 == puVar4) {
    return 0;
  }
  puVar1 = *(undefined4 **)(in_EAX + 0x1c);
  for (; puVar4 != puVar1; puVar4 = puVar4 + 1) {
    *puVar5 = *puVar4;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 **)(in_EAX + 0x1c) = puVar5;
  param_1 = (ushort *)(uint)*puVar2;
  *(undefined4 *)(*(int *)(in_EAX + 0x38) + (int)param_1 * 4) = 0;
  FUN_006de9c0();
  return 1;
}

