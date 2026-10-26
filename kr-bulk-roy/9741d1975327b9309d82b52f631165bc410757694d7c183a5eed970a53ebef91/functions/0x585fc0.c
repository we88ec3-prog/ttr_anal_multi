
void FUN_00585fc0(void)

{
  void *pvVar1;
  DWORD DVar2;
  uintptr_t uVar3;
  void *in_ECX;
  
  FUN_007459c0();
  pvVar1 = in_ECX;
  if ((*(byte *)((int)in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)((int)in_ECX + 0x60) == 0) goto LAB_00585ffc;
    pvVar1 = (void *)FUN_00745c20();
  }
  if (((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 0x60) != 0)) &&
     ((*(uint *)((int)pvVar1 + 0x28) >> 0xc & 1) == 0)) {
    FUN_0074a010(pvVar1);
  }
LAB_00585ffc:
  DVar2 = timeGetTime();
  *(DWORD *)((int)in_ECX + 0xf8) = DVar2;
  *(undefined4 *)((int)in_ECX + 0xfc) = 1;
  uVar3 = __beginthread(FUN_00586080,0,in_ECX);
  *(uintptr_t *)((int)in_ECX + 0x100) = uVar3;
  return;
}

