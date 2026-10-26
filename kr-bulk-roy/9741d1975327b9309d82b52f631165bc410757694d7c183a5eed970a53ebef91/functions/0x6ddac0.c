
/* WARNING: Removing unreachable block (ram,0x006ddae2) */

uint FUN_006ddac0(char *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *in_EDX;
  
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar4 = (int)pcVar3 - (int)(param_1 + 1);
  uVar2 = *(uint *)(in_EDX + 0x10);
  uVar5 = uVar2;
  if (uVar4 <= uVar2) {
    uVar5 = uVar4;
  }
  if (0xf < *(uint *)(in_EDX + 0x14)) {
    in_EDX = *(char **)in_EDX;
  }
  uVar5 = __strnicmp(in_EDX,param_1,uVar5);
  if (uVar5 == 0) {
    if (uVar2 < uVar4) {
      return 0xffffffff;
    }
    uVar5 = (uint)(uVar2 != uVar4);
  }
  return uVar5;
}

