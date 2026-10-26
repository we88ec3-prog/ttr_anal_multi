
undefined4 * FUN_0076f140(undefined4 param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ec98;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(param_1) {
  case 0xbf6a:
    pvVar1 = _malloc(0x2f4);
    local_8 = 0;
    if (pvVar1 != (void *)0x0) {
      puVar2 = (undefined4 *)FUN_00778440(pvVar1,unaff_EDI);
      ExceptionList = local_10;
      return puVar2;
    }
    break;
  case 0xbf6b:
    puVar2 = _malloc(0x54);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[2] = unaff_EDI;
      *puVar2 = FoxUI::FXUIBackgroundSingle::vftable;
      DAT_00fba828 = DAT_00fba828 + 1;
      puVar2[1] = DAT_00fba828;
      puVar2[4] = 0;
      puVar2[3] = FoxUI::FXUIImageSetItemLink::vftable;
      puVar2[9] = 0;
      puVar2[10] = 7;
      *(undefined2 *)(puVar2 + 5) = 0;
      puVar2[0x11] = 7;
      puVar2[0x10] = 0;
      *(undefined2 *)(puVar2 + 0xc) = 0;
      puVar2[0x14] = 0;
      *(undefined2 *)(puVar2 + 0x13) = 0;
      ExceptionList = local_10;
      return puVar2;
    }
    break;
  case 0xbf6c:
    puVar2 = _malloc(0x10);
    if (puVar2 != (undefined4 *)0x0) {
      DAT_00fba828 = DAT_00fba828 + 1;
      puVar2[1] = DAT_00fba828;
      puVar2[2] = unaff_EDI;
      *puVar2 = FoxUI::FXUIBackgroundColor::vftable;
      puVar2[3] = 0xff000000;
      ExceptionList = local_10;
      return puVar2;
    }
    break;
  case 0xbf6d:
    puVar2 = _malloc(0x18);
    if (puVar2 != (undefined4 *)0x0) {
      DAT_00fba828 = DAT_00fba828 + 1;
      puVar2[1] = DAT_00fba828;
      puVar2[2] = unaff_EDI;
      *puVar2 = FoxUI::FXUIBackgroundColorLine::vftable;
      puVar2[3] = 0xff000000;
      puVar2[4] = 0xffff0000;
      puVar2[5] = 1;
      ExceptionList = local_10;
      return puVar2;
    }
    break;
  case 0xbf6e:
    puVar2 = _malloc(0x54);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[2] = unaff_EDI;
      *puVar2 = FoxUI::FXUIBackgroundPattern::vftable;
      DAT_00fba828 = DAT_00fba828 + 1;
      puVar2[1] = DAT_00fba828;
      puVar2[4] = 0;
      puVar2[3] = FoxUI::FXUIImageSetItemLink::vftable;
      puVar2[9] = 0;
      puVar2[10] = 7;
      *(undefined2 *)(puVar2 + 5) = 0;
      puVar2[0x11] = 7;
      puVar2[0x10] = 0;
      *(undefined2 *)(puVar2 + 0xc) = 0;
      puVar2[0x14] = 0;
      *(undefined1 *)(puVar2 + 0x13) = 0;
      ExceptionList = local_10;
      return puVar2;
    }
    break;
  case 0xbf6f:
    pvVar1 = _malloc(0x114);
    local_8 = 1;
    if (pvVar1 != (void *)0x0) {
      puVar2 = (undefined4 *)FUN_00779a60(pvVar1,unaff_EDI);
      ExceptionList = local_10;
      return puVar2;
    }
    break;
  case 0xbf70:
    puVar2 = _malloc(0x114);
    local_8 = 2;
    if (puVar2 != (undefined4 *)0x0) {
      FUN_00779a60(puVar2,unaff_EDI);
      puVar2[0x40] = 10;
      puVar2[0x42] = 10;
      *puVar2 = FoxUI::FXUIBackground3Y::vftable;
      puVar2[0x3f] = 0;
      puVar2[0x41] = 0;
      ExceptionList = local_10;
      return puVar2;
    }
    break;
  case 0xbfcc:
    pvVar1 = _malloc(0x1c);
    if (pvVar1 != (void *)0x0) {
      puVar2 = (undefined4 *)FUN_0077cd10(unaff_EDI);
      ExceptionList = local_10;
      return puVar2;
    }
    break;
  case 0xbfcd:
    pvVar1 = _malloc(0x40);
    if (pvVar1 != (void *)0x0) {
      puVar2 = (undefined4 *)FUN_0077cf50(unaff_EDI);
      ExceptionList = local_10;
      return puVar2;
    }
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}

