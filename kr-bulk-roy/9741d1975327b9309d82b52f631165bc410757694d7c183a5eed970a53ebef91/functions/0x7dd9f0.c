
uint FUN_007dd9f0(void)

{
  uint uVar1;
  uint *in_EAX;
  undefined4 uVar2;
  
  *in_EAX = *in_EAX + 1;
  uVar1 = *in_EAX;
  if (0x7fffffff < uVar1) {
    MessageBoxA((HWND)0x0,&DAT_00c50400,"error",0);
    return *in_EAX;
  }
  uVar2 = FUN_0057ef20();
  FUN_0082f200(in_EAX + 1,uVar2);
  return uVar1;
}

