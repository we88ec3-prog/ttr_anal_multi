
int FUN_0080dac0(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  LONG *Target;
  
  Target = (LONG *)(in_ECX + 0xc);
  if (*(int *)(in_ECX + 0xc) != 0) {
    return 1;
  }
  if (*(int *)(in_ECX + 0x3c) == 0) {
    return 0;
  }
  piVar2 = (int *)(in_ECX + 0x40);
  iVar1 = FUN_0080da50(*(int *)(in_ECX + 0x3c));
  if (iVar1 == 0) {
    if (0xf < *(uint *)(in_ECX + 0x54)) {
      piVar2 = (int *)*piVar2;
    }
    FUN_006edb60("SoundSolo.Load(): File not found: %s",piVar2);
    Target = (LONG *)(in_ECX + 0x14);
  }
  else {
    *(undefined4 *)(in_ECX + 0x34) = 600;
  }
  InterlockedExchange(Target,1);
  InterlockedExchange((LONG *)(in_ECX + 0x10),0);
  return iVar1;
}

