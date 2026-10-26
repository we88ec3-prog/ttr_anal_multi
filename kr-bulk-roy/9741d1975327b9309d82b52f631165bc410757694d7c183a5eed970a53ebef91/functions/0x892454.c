
/* Library Function - Single Match
    @x64tow_s@24
   
   Library: Visual Studio 2010 Release
   __fastcall x64tow_s,24 */

int __fastcall
x64tow_s(undefined4 param_1,undefined4 param_2,int param_3,int param_4,uint param_5,int param_6,
        short *param_7)

{
  short *psVar1;
  int *piVar2;
  short sVar3;
  uint extraout_ECX;
  short *psVar4;
  short *unaff_EDI;
  bool bVar5;
  bool bVar6;
  longlong lVar7;
  int iVar8;
  uint local_8;
  
  if ((unaff_EDI == (short *)0x0) || (param_5 == 0)) {
LAB_00892461:
    piVar2 = __errno();
    iVar8 = 0x16;
  }
  else {
    *unaff_EDI = 0;
    if ((param_7 != (short *)0x0) + 1 < param_5) {
      if (param_6 - 2U < 0x23) {
        bVar6 = param_7 != (short *)0x0;
        param_7 = unaff_EDI;
        if (bVar6) {
          *unaff_EDI = 0x2d;
          bVar5 = param_3 != 0;
          param_3 = -param_3;
          param_4 = -(param_4 + (uint)bVar5);
          param_7 = unaff_EDI + 1;
        }
        lVar7 = CONCAT44(param_4,param_3);
        local_8 = (uint)bVar6;
        psVar1 = param_7;
        do {
          psVar4 = psVar1;
          lVar7 = __aulldvrm(lVar7,param_6,0);
          if (extraout_ECX < 10) {
            sVar3 = (short)extraout_ECX + 0x30;
          }
          else {
            sVar3 = (short)extraout_ECX + 0x57;
          }
          *psVar4 = sVar3;
          local_8 = local_8 + 1;
        } while ((lVar7 != 0) && (psVar1 = psVar4 + 1, local_8 < param_5));
        if (local_8 < param_5) {
          psVar4[1] = 0;
          do {
            sVar3 = *psVar4;
            *psVar4 = *param_7;
            *param_7 = sVar3;
            param_7 = param_7 + 1;
            psVar4 = psVar4 + -1;
          } while (param_7 < psVar4);
          return 0;
        }
        *unaff_EDI = 0;
        piVar2 = __errno();
        iVar8 = 0x22;
        *piVar2 = 0x22;
        goto LAB_0089246b;
      }
      goto LAB_00892461;
    }
    piVar2 = __errno();
    iVar8 = 0x22;
  }
  *piVar2 = iVar8;
LAB_0089246b:
  FUN_00893343();
  return iVar8;
}

