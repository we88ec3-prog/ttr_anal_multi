
void FUN_007444b0(undefined4 param_1)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x8c) = in_EAX;
  *(undefined4 *)(in_ECX + 0x90) = param_1;
  if (*(int **)(in_ECX + 0x94) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x94) + 0x1c))(1);
    *(undefined4 *)(in_ECX + 0x94) = 0;
  }
  if (*(int **)(in_ECX + 0x98) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x98) + 0x1c))(1);
    *(undefined4 *)(in_ECX + 0x98) = 0;
  }
  if (*(int **)(in_ECX + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x9c) + 0x1c))(1);
    *(undefined4 *)(in_ECX + 0x9c) = 0;
  }
  if (*(int **)(in_ECX + 0xa0) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xa0) + 0x1c))(1);
    *(undefined4 *)(in_ECX + 0xa0) = 0;
  }
  if ((*(byte *)(in_ECX + 0x8c) & 2) != 0) {
    uVar1 = FUN_0076f140(param_1);
    *(undefined4 *)(in_ECX + 0x94) = uVar1;
  }
  if ((*(byte *)(in_ECX + 0x8c) & 4) != 0) {
    uVar1 = FUN_0076f140(param_1);
    *(undefined4 *)(in_ECX + 0x98) = uVar1;
  }
  if ((*(byte *)(in_ECX + 0x8c) & 8) != 0) {
    uVar1 = FUN_0076f140(param_1);
    *(undefined4 *)(in_ECX + 0x9c) = uVar1;
  }
  if ((*(byte *)(in_ECX + 0x8c) & 0x10) != 0) {
    uVar1 = FUN_0076f140(param_1);
    *(undefined4 *)(in_ECX + 0xa0) = uVar1;
  }
  return;
}

