
undefined4 FUN_00797790(void)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  float10 fVar6;
  undefined8 uVar7;
  undefined1 local_18 [16];
  float local_8;
  
  iVar1 = 0;
  if (0 < (int)(*(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) & 0xfffffffcU)) {
    piVar2 = *(int **)(in_EAX + 4);
    do {
      if (*(int *)(in_EAX + 0x40) < *(int *)(*piVar2 + 0x24)) break;
      *(int *)(in_EAX + 0x38) = iVar1;
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar1 < *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2);
  }
  iVar1 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2;
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = *(undefined4 **)(*(int *)(in_EAX + 4) + *(int *)(in_EAX + 0x38) * 4);
  }
  if (*(int *)(in_EAX + 0x38) + 1 < iVar1) {
    iVar1 = *(int *)(*(int *)(in_EAX + 4) + 4 + *(int *)(in_EAX + 0x38) * 4);
  }
  else {
    iVar1 = 0;
  }
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  iVar4 = *(int *)(in_EAX + 0x40);
  if ((puVar3[9] == iVar4) || (puVar3[7] == 4)) {
    puVar5 = (undefined4 *)(in_EAX + 0x14);
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  else if (((iVar1 != 0) && ((int)puVar3[9] < iVar4)) && (iVar4 < *(int *)(iVar1 + 0x24))) {
    local_8 = (float)(iVar4 - puVar3[9]) / (float)(*(int *)(iVar1 + 0x24) - puVar3[9]);
    fVar6 = (float10)FUN_00797670(local_8,puVar3[7],puVar3[8]);
    local_8 = (float)fVar6;
    uVar7 = FUN_00797560(local_18,local_8);
    iVar4 = (int)((ulonglong)uVar7 >> 0x20);
    puVar3 = (undefined4 *)uVar7;
    *(undefined4 *)(in_EAX + 0x14) = *puVar3;
    *(undefined4 *)(in_EAX + 0x18) = puVar3[1];
    *(undefined4 *)(in_EAX + 0x1c) = puVar3[2];
    *(float *)(in_EAX + 0x20) =
         local_8 * (*(float *)(iVar1 + 0xc) - *(float *)(iVar4 + 0xc)) + *(float *)(iVar4 + 0xc);
    *(float *)(in_EAX + 0x24) =
         *(float *)(iVar4 + 0x10) + local_8 * (*(float *)(iVar1 + 0x10) - *(float *)(iVar4 + 0x10));
    *(float *)(in_EAX + 0x28) =
         *(float *)(iVar4 + 0x14) + local_8 * (*(float *)(iVar1 + 0x14) - *(float *)(iVar4 + 0x14));
    *(float *)(in_EAX + 0x2c) =
         *(float *)(iVar4 + 0x18) + (*(float *)(iVar1 + 0x18) - *(float *)(iVar4 + 0x18)) * local_8;
    *(undefined4 *)(in_EAX + 0x30) = *(undefined4 *)(iVar4 + 0x1c);
    *(undefined4 *)(in_EAX + 0x34) = *(undefined4 *)(iVar4 + 0x20);
    return 1;
  }
  return 1;
}

