
undefined4 FUN_0085a950(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  
  if ((in_EAX != 0) && (*(int *)(in_EAX + 0xec) != 0)) {
    (**(code **)(**(int **)(in_EAX + 0xec) + 4))(*(int **)(in_EAX + 0xec));
    piVar1 = *(int **)(in_EAX + 0xec);
    if (piVar1 != (int *)0x0) {
      if (param_1 != 0) {
        (**(code **)(*piVar1 + 0x9c))(piVar1,param_1);
        (**(code **)(*piVar1 + 8))(piVar1);
        return 1;
      }
      (**(code **)(**(int **)(in_EAX + 0x430) + 4))(*(int **)(in_EAX + 0x430));
      piVar2 = *(int **)(in_EAX + 0x430);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x9c))(piVar1,piVar2);
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      (**(code **)(*piVar1 + 8))(piVar1);
      return 1;
    }
  }
  return 0;
}

