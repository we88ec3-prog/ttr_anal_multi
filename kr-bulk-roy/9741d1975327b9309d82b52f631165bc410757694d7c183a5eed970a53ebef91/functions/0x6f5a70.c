
void FUN_006f5a70(int param_1)

{
  int in_EAX;
  int in_ECX;
  int unaff_EDI;
  int local_10;
  
  if (in_EAX != 0) {
    FUN_006f50f0();
  }
  local_10 = *(int *)(in_ECX + 8) + (param_1 + 1) * -0x10;
  FUN_006fe770(FUN_006f5a50,&local_10,local_10 - *(int *)(in_ECX + 0x20));
  if (unaff_EDI == -1) {
    if (*(uint *)(*(int *)(in_ECX + 0x14) + 8) <= *(uint *)(in_ECX + 8)) {
      *(uint *)(*(int *)(in_ECX + 0x14) + 8) = *(uint *)(in_ECX + 8);
    }
  }
  return;
}

