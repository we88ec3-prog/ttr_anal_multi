
/* Library Function - Single Match
    int __cdecl _fpcvt(char *,unsigned int,struct _strflt *,int,int *,int *)
   
   Library: Visual Studio 2010 Release */

int __cdecl
_fpcvt(char *param_1,uint param_2,_strflt *param_3,int param_4,int *param_5,int *param_6)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  uint in_EDX;
  STRFLT unaff_EDI;
  
  iVar2 = in_ECX;
  if (in_ECX < 1) {
    iVar2 = 0;
  }
  if (in_EDX < iVar2 + 2U) {
    piVar1 = __errno();
    iVar2 = 0x22;
    *piVar1 = 0x22;
    FUN_00893343();
  }
  else {
    iVar2 = in_EDX - 2;
    if (in_ECX <= (int)(in_EDX - 2)) {
      iVar2 = in_ECX;
    }
    iVar2 = __fptostr(param_1,in_EDX,iVar2,unaff_EDI);
    if (iVar2 == 0) {
      param_3->sign = (uint)(unaff_EDI->sign == 0x2d);
      *(int *)param_2 = unaff_EDI->decpt;
      iVar2 = 0;
    }
    else {
      piVar1 = __errno();
      *piVar1 = iVar2;
    }
  }
  return iVar2;
}

