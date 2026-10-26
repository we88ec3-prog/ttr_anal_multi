
void FUN_006dcc70(undefined4 param_1)

{
  int in_EAX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)(in_EAX + 0x10) != 0) {
    FUN_007a5c50(*(int *)(in_EAX + 0x10),param_1,1);
    *(undefined4 *)(*(int *)(in_EAX + 0x10) + 0x124) = 1;
  }
  if (*(int *)(in_EAX + 0xc) != 0) {
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0x3f800000;
    FUN_00780830(&local_18,0x3fb2b8c3,0,*(undefined4 *)(in_EAX + 0x18));
    FUN_0077f030(*(undefined4 *)(in_EAX + 0x1c),*(undefined4 *)(in_EAX + 0x20),
                 *(undefined4 *)(in_EAX + 0x24));
    FUN_0077efc0();
    FUN_00780150(*(int *)(in_EAX + 8),*(undefined4 *)(*(int *)(in_EAX + 8) + 0x30));
  }
  return;
}

