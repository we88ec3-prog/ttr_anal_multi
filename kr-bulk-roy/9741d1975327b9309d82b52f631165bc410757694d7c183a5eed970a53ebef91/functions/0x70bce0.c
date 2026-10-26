
undefined4 FUN_0070bce0(int param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if (puVar3 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar3 != &DAT_00c0bfc8) && (puVar3[2] == 5)) goto LAB_0070bd3f;
    if ((*(undefined4 **)(param_1 + 8) <= puVar3) ||
       ((puVar3 == &DAT_00c0bfc8 || (puVar3[2] == -1)))) goto LAB_0070bd11;
    pcVar2 = (&PTR_DAT_00c0be1c)[puVar3[2]];
  }
  else {
LAB_0070bd11:
    pcVar2 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar2);
  FUN_006f5da0(1);
LAB_0070bd3f:
  FUN_006f5f30(param_1,"\'setn\' is obsolete");
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 <= puVar3) {
    puVar3 = &DAT_00c0bfc8;
  }
  *puVar1 = *puVar3;
  puVar1[1] = puVar3[1];
  puVar1[2] = puVar3[2];
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

