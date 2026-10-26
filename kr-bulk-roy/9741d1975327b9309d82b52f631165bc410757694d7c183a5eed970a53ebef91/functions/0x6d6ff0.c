
/* WARNING: Removing unreachable block (ram,0x006d704a) */
/* WARNING: Removing unreachable block (ram,0x006d7050) */
/* WARNING: Removing unreachable block (ram,0x006d705e) */

void FUN_006d6ff0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint in_EAX;
  int iVar3;
  int in_ECX;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 local_18;
  undefined1 *local_14;
  int local_10;
  uint local_c;
  
  if (in_EAX < 10) {
    uVar4 = 0;
  }
  else {
    uVar4 = in_EAX - 10 >> 2;
  }
  local_c = (uint)*(ushort *)(in_ECX + 6);
  local_18 = uVar4;
  iVar3 = FUN_006d6d80(param_1,*(undefined4 *)(in_ECX + 2),local_c);
  if (*(int *)(iVar3 + 8) != *(int *)(iVar3 + 0xc)) {
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 8);
  }
  if (uVar4 == 0) {
    *(undefined4 *)(iVar3 + 0x18) = 1;
    return;
  }
  puVar5 = (undefined1 *)(in_ECX + 0xd);
  local_10 = iVar3;
  do {
    puVar1 = *(undefined4 **)(iVar3 + 0xc);
    local_18 = CONCAT13(*puVar5,*(undefined3 *)(puVar5 + -3));
    local_14 = puVar5;
    if (&local_18 < puVar1) {
      puVar2 = *(undefined4 **)(iVar3 + 8);
      if (&local_18 < puVar2) goto LAB_006d70c6;
      if (puVar1 == *(undefined4 **)(iVar3 + 0x10)) {
        FUN_0068c010();
      }
      if (*(undefined4 **)(iVar3 + 0xc) != (undefined4 *)0x0) {
        **(undefined4 **)(iVar3 + 0xc) =
             *(undefined4 *)(*(uint *)(iVar3 + 8) + ((int)&local_18 - (int)puVar2 >> 2) * 4);
      }
    }
    else {
LAB_006d70c6:
      if (puVar1 == *(undefined4 **)(iVar3 + 0x10)) {
        FUN_0068c010();
      }
      local_14 = puVar5;
      if (*(undefined4 **)(iVar3 + 0xc) != (undefined4 *)0x0) {
        **(undefined4 **)(iVar3 + 0xc) = local_18;
      }
    }
    *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 4;
    puVar5 = local_14 + 4;
    uVar4 = uVar4 - 1;
    if (uVar4 == 0) {
      *(undefined4 *)(local_10 + 0x18) = 1;
      return;
    }
  } while( true );
}

