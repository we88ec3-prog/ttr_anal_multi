
void FUN_00432810(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *in_ECX;
  undefined4 *puVar4;
  _Lockit local_c [8];
  
  puVar1 = (uint *)in_ECX[0xe];
  *in_ECX = std::basic_streambuf<wchar_t,std::char_traits<wchar_t>_>::vftable;
  if (puVar1 != (uint *)0x0) {
    uVar2 = *puVar1;
    if (uVar2 != 0) {
      std::_Lockit::_Lockit(local_c,0);
      iVar3 = *(int *)(uVar2 + 4);
      if ((iVar3 != 0) && (iVar3 != -1)) {
        *(int *)(uVar2 + 4) = iVar3 + -1;
      }
      iVar3 = *(int *)(uVar2 + 4);
      FUN_0087dd6f();
      puVar4 = (undefined4 *)(~-(uint)(iVar3 != 0) & uVar2);
      if (puVar4 != (undefined4 *)0x0) {
        (**(code **)*puVar4)(1);
      }
    }
    FUN_0089120c(puVar1);
  }
  FUN_0087dda0();
  return;
}

