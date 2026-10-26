
/* Library Function - Single Match
    int __cdecl _wcrtomb_s_l(int *,char *,unsigned int,wchar_t,int *,struct localeinfo_struct *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl
_wcrtomb_s_l(int *param_1,char *param_2,uint param_3,wchar_t param_4,int *param_5,
            localeinfo_struct *param_6)

{
  int iVar1;
  int *piVar2;
  int *unaff_ESI;
  undefined4 *unaff_EDI;
  undefined2 in_stack_00000012;
  int local_18 [2];
  int local_10;
  char local_c;
  BOOL local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_18,_param_4);
  if (unaff_EDI != (undefined4 *)0x0) {
    *unaff_EDI = 0;
  }
  if (*(int *)(local_18[0] + 0x14) == 0) {
    if (0xff < (ushort)param_3) {
LAB_00892a85:
      piVar2 = __errno();
      *piVar2 = 0x2a;
      if (unaff_ESI != (int *)0x0) {
        *unaff_ESI = -1;
      }
      piVar2 = __errno();
      iVar1 = *piVar2;
      if (local_c == '\0') {
        return iVar1;
      }
      *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
      return iVar1;
    }
    *(char *)param_1 = (char)param_3;
    if (unaff_ESI != (int *)0x0) {
      *unaff_ESI = 1;
    }
  }
  else {
    local_8 = 0;
    iVar1 = WideCharToMultiByte(*(UINT *)(local_18[0] + 4),0,(LPCWSTR)&param_3,1,(LPSTR)param_1,
                                (int)param_2,(LPCSTR)0x0,&local_8);
    if ((iVar1 == 0) || (local_8 != 0)) goto LAB_00892a85;
    if (unaff_ESI != (int *)0x0) {
      *unaff_ESI = iVar1;
    }
  }
  if (local_c != '\0') {
    *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
  }
  return 0;
}

