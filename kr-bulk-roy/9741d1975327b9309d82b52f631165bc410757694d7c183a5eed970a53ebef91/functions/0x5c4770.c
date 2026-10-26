
void FUN_005c4770(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  LPCWSTR lpText;
  undefined **ppuVar4;
  undefined4 local_42c;
  uint local_418;
  
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ppuVar4 = &PTR_u_UI_ImageSets_Botmenu_FIS_00d65a40;
  do {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    FUN_0077c710(*ppuVar4);
    cVar2 = FUN_00774f60(uVar1);
    if (cVar2 == '\0') {
      lpText = (LPCWSTR)FUN_004ed610();
      if (7 < *(uint *)(lpText + 10)) {
        lpText = *(LPCWSTR *)lpText;
      }
      MessageBoxW((HWND)0x0,lpText,L"Error",0);
      if (7 < local_418) {
        FUN_0089120c(local_42c);
      }
    }
    ppuVar4 = ppuVar4 + 1;
  } while ((int)ppuVar4 < 0xd65bd0);
  FUN_005c8190();
  FUN_005c8190();
  FUN_005c8190();
  FUN_005c8190();
  FUN_005c8190();
  FUN_005c8190();
  FUN_005c8190();
  FUN_005c8190();
  FUN_005c8190();
  FUN_005c8190();
  FUN_005c8190();
  FUN_00402160(L"Image/Icon/Quest/SlotEmpty.dds",0x1e);
  FUN_00402160(L"Image/Icon/Quest/SlotEmpty.dds",0x1e);
  FUN_00402160(L"Image/Icon/Quest/SlotEmpty.dds",0x1e);
  FUN_005c4ca0(param_1);
  FUN_005c4900();
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

