
void FUN_008e0520(undefined4 param_1)

{
  int *piVar1;
  int in_EAX;
  undefined4 *in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(*(int *)(in_EAX + 0x80) + 0x30) != 0) {
    local_c = *in_ECX;
    local_8 = param_1;
    piVar1 = *(int **)(*(int *)(in_EAX + 0x80) + 0x30);
    (**(code **)(*piVar1 + 4))(piVar1[1],&local_c);
    return;
  }
  FUN_008ddf70();
  return;
}

