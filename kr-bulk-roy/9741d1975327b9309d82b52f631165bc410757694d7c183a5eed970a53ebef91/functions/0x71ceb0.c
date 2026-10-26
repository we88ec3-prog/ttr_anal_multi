
undefined4 FUN_0071ceb0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_EAX;
  undefined4 *puVar4;
  int in_EDX;
  undefined4 *puVar5;
  
  if (in_EDX != 0) {
    if ((in_EDX != 1) && (puVar5 = param_1 + 2, puVar5 < in_EAX)) {
      do {
        uVar2 = *param_1;
        uVar3 = param_1[1];
        puVar4 = in_EAX + -2;
        *param_1 = in_EAX[-2];
        param_1[1] = in_EAX[-1];
        puVar1 = puVar5 + 2;
        *puVar4 = uVar2;
        in_EAX[-1] = uVar3;
        in_EAX = puVar4;
        param_1 = puVar5;
        puVar5 = puVar1;
      } while (puVar1 < puVar4);
    }
    return 1;
  }
  FUN_00722890(param_1);
  return 1;
}

