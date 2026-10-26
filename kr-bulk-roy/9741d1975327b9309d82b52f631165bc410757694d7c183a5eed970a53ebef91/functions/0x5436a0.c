
/* WARNING: Removing unreachable block (ram,0x005436b4) */

bool FUN_005436a0(void)

{
  uint uVar1;
  uint uVar2;
  char *in_EAX;
  uint uVar3;
  char *in_ECX;
  
  uVar1 = *(uint *)(in_EAX + 0x10);
  if (0xf < *(uint *)(in_EAX + 0x14)) {
    in_EAX = *(char **)in_EAX;
  }
  uVar2 = *(uint *)(in_ECX + 0x10);
  uVar3 = uVar2;
  if (uVar1 <= uVar2) {
    uVar3 = uVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x14)) {
    in_ECX = *(char **)in_ECX;
  }
  uVar3 = __strnicmp(in_ECX,in_EAX,uVar3);
  if (uVar3 == 0) {
    if (uVar2 < uVar1) {
      return true;
    }
    uVar3 = (uint)(uVar2 != uVar1);
  }
  return (int)uVar3 < 0;
}

