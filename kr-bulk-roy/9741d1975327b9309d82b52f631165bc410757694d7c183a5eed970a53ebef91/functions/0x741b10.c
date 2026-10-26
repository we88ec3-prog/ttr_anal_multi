
undefined4 * FUN_00741b10(undefined4 *param_1,int *param_2,int *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int in_EAX;
  
  puVar1 = param_1;
  if ((param_2 == (int *)**(int **)(in_EAX + 4)) && (param_3 == *(int **)(in_EAX + 4))) {
    FUN_007420d0();
    *puVar1 = **(undefined4 **)(in_EAX + 4);
    return puVar1;
  }
  if (param_2 != param_3) {
    do {
      piVar2 = param_2;
      FUN_00741b70();
      FUN_00741de0(in_EAX,&param_1,piVar2);
    } while (param_2 != param_3);
  }
  *puVar1 = param_2;
  return puVar1;
}

