
void FUN_0083b370(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x60))();
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      local_c = 0;
      local_8 = 0;
      (**(code **)(*in_ECX + 100))(iVar2,&local_c,&local_8);
      (**(code **)(*in_ECX + 0x5c))(&local_8);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return;
}

