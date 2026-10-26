
void FUN_00761600(undefined4 param_1)

{
  undefined4 in_EAX;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x141) != '\0') {
    FUN_00757e40(in_EAX,param_1);
    FUN_006ee170(param_1);
    return;
  }
  FUN_00757e40(in_EAX,param_1);
  return;
}

