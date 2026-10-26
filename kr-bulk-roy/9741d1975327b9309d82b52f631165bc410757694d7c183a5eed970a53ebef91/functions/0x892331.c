
/* Library Function - Single Match
    _xtow_s@20
   
   Library: Visual Studio 2010 Release
   __stdcall xtow_s,20 */

int xtow_s(uint param_1,uint param_2,int param_3)

{
  short *psVar1;
  uint in_EAX;
  int *piVar2;
  short *in_ECX;
  short *psVar3;
  short *psVar4;
  short sVar5;
  uint uVar6;
  int iStack_14;
  
  if (in_ECX == (short *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_00893343();
    return 0x16;
  }
  if (param_1 == 0) {
LAB_0089235c:
    piVar2 = __errno();
    iStack_14 = 0x16;
  }
  else {
    *in_ECX = 0;
    if ((param_3 != 0) + 1 < param_1) {
      if (param_2 - 2 < 0x23) {
        psVar3 = in_ECX;
        if (param_3 != 0) {
          *in_ECX = 0x2d;
          psVar3 = in_ECX + 1;
          in_EAX = -in_EAX;
        }
        uVar6 = (uint)(param_3 != 0);
        psVar1 = psVar3;
        do {
          psVar4 = psVar1;
          sVar5 = (short)(in_EAX % param_2);
          if (in_EAX % param_2 < 10) {
            sVar5 = sVar5 + 0x30;
          }
          else {
            sVar5 = sVar5 + 0x57;
          }
          *psVar4 = sVar5;
          uVar6 = uVar6 + 1;
        } while ((in_EAX / param_2 != 0) &&
                (in_EAX = in_EAX / param_2, psVar1 = psVar4 + 1, uVar6 < param_1));
        if (uVar6 < param_1) {
          psVar4[1] = 0;
          do {
            sVar5 = *psVar4;
            *psVar4 = *psVar3;
            *psVar3 = sVar5;
            psVar4 = psVar4 + -1;
            psVar3 = psVar3 + 1;
          } while (psVar3 < psVar4);
          return 0;
        }
        *in_ECX = 0;
        piVar2 = __errno();
        iStack_14 = 0x22;
        *piVar2 = 0x22;
        goto LAB_00892366;
      }
      goto LAB_0089235c;
    }
    piVar2 = __errno();
    iStack_14 = 0x22;
  }
  *piVar2 = iStack_14;
LAB_00892366:
  FUN_00893343();
  return iStack_14;
}

