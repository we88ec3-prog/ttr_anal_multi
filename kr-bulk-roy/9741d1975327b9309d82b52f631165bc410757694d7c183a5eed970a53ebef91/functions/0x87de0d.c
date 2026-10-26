
/* Library Function - Single Match
    private: static void __cdecl std::ios_base::_Ios_base_dtor(class std::ios_base *)
   
   Library: Visual Studio 2010 Release */

void __cdecl std::ios_base::_Ios_base_dtor(ios_base *param_1)

{
  char *pcVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 8) != 0) {
    pcVar1 = &DAT_00f8c830 + *(int *)(param_1 + 8);
    *pcVar1 = *pcVar1 + -1;
    if ('\0' < *pcVar1) {
      return;
    }
  }
  _Tidy(param_1);
  iVar2 = *(int *)(param_1 + 0x30);
  if (iVar2 != 0) {
    FUN_004327c0();
    FUN_0089120c(iVar2);
  }
  return;
}

