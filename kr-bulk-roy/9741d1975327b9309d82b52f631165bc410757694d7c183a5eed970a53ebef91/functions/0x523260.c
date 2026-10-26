
void FUN_00523260(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch((&DAT_0052342c)[in_ECX]) {
  case 0:
    puVar1 = (undefined4 *)FUN_00891268(0x10);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 3;
      *(undefined2 *)(puVar1 + 2) = 0;
      *(undefined2 *)((int)puVar1 + 10) = 0;
      *puVar1 = ITEM::UsableAction::ItemUsableSkillcast::vftable;
      *(undefined2 *)(puVar1 + 3) = 0;
      *(undefined1 *)((int)puVar1 + 0xe) = 0;
      return;
    }
    break;
  case 1:
    puVar1 = (undefined4 *)FUN_00891268(0x10);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 4;
      *(undefined2 *)(puVar1 + 2) = 0;
      *(undefined2 *)((int)puVar1 + 10) = 0;
      *puVar1 = ITEM::UsableAction::ItemUsableRebirth::vftable;
      *(undefined1 *)(puVar1 + 3) = 0;
      return;
    }
    break;
  case 2:
    puVar1 = (undefined4 *)FUN_00891268(0x10);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 2;
      puVar1[2] = 0;
      *puVar1 = ITEM::UsableAction::ItemUsableValue::vftable;
      *(undefined2 *)(puVar1 + 3) = 0;
      return;
    }
    break;
  case 3:
    puVar1 = (undefined4 *)FUN_00891268(0x10);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 5;
      *(undefined2 *)(puVar1 + 2) = 0;
      *(undefined2 *)((int)puVar1 + 10) = 0;
      *puVar1 = ITEM::UsableAction::ItemUsableExpBook::vftable;
      puVar1[3] = 0;
      return;
    }
    break;
  case 4:
    puVar1 = (undefined4 *)FUN_00891268(0x10);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 6;
      puVar1[2] = 0;
      *puVar1 = ITEM::UsableAction::ItemUsableFirework::vftable;
      *(undefined2 *)(puVar1 + 3) = 0;
      return;
    }
    break;
  case 5:
    puVar1 = (undefined4 *)FUN_00891268(0x10);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 7;
      puVar1[2] = 0;
      *puVar1 = ITEM::UsableAction::ItemUsableEventObject::vftable;
      puVar1[3] = 0;
      return;
    }
    break;
  case 6:
    puVar1 = (undefined4 *)FUN_00891268(0xc);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 1;
      puVar1[2] = 0;
      *puVar1 = ITEM::UsableAction::ItemUsableNoValue::vftable;
      return;
    }
    break;
  case 7:
    puVar1 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 8;
      *(undefined2 *)(puVar1 + 2) = 0;
      *(undefined2 *)((int)puVar1 + 10) = 0;
      *puVar1 = ITEM::UsableAction::ItemUsableFlag::vftable;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      return;
    }
    break;
  case 8:
    puVar1 = (undefined4 *)FUN_00891268(0x20);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 9;
      *(undefined2 *)(puVar1 + 2) = 0;
      *(undefined2 *)((int)puVar1 + 10) = 0;
      *puVar1 = ITEM::UsableAction::ItemUsableItemEnchant::vftable;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      *(undefined1 *)(puVar1 + 7) = 0;
      return;
    }
  }
  return;
}

