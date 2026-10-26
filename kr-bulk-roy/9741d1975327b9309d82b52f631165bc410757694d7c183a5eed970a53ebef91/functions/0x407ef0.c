
/* WARNING: Removing unreachable block (ram,0x00407f09) */

uint FUN_00407ef0(void)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *in_ECX;
  int unaff_EDI;
  
  pcVar1 = in_ECX + 1;
  do {
    cVar2 = *in_ECX;
    in_ECX = in_ECX + 1;
  } while (cVar2 != '\0');
  uVar4 = (int)in_ECX - (int)pcVar1;
  uVar3 = *(uint *)(unaff_EDI + 0x10);
  uVar5 = uVar3;
  if (uVar4 <= uVar3) {
    uVar5 = uVar4;
  }
  uVar5 = FUN_00407e70(uVar5);
  if (uVar5 == 0) {
    if (uVar3 < uVar4) {
      return 0xffffffff;
    }
    uVar5 = (uint)(uVar3 != uVar4);
  }
  return uVar5;
}

