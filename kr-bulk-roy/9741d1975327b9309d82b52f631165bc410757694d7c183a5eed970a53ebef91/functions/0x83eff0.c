
/* WARNING: Removing unreachable block (ram,0x0083f006) */
/* WARNING: Removing unreachable block (ram,0x0083f01b) */

uint FUN_0083eff0(char *param_1,uint param_2)

{
  char cVar1;
  undefined4 *in_EAX;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  
  uVar4 = in_EAX[4];
  if (param_2 != 0) {
    if (param_2 <= uVar4) {
      puVar5 = in_EAX;
      if (0xf < (uint)in_EAX[5]) {
        puVar5 = (undefined4 *)*in_EAX;
      }
      pcVar6 = (char *)((int)puVar5 + (uVar4 - param_2));
      cVar1 = *param_1;
      while( true ) {
        if ((*pcVar6 == cVar1) && (iVar2 = FUN_00407e70(param_2), iVar2 == 0)) {
          if (0xf < (uint)in_EAX[5]) {
            in_EAX = (undefined4 *)*in_EAX;
          }
          return (int)pcVar6 - (int)in_EAX;
        }
        pcVar3 = (char *)FUN_00403030();
        if (pcVar6 == pcVar3) break;
        pcVar6 = pcVar6 + -1;
      }
    }
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

