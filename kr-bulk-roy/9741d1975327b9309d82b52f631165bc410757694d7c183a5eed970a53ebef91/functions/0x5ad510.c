
void FUN_005ad510(int param_1)

{
  int in_ECX;
  
  FUN_005ac600(param_1);
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf4267:
    FUN_005ad470();
    return;
  case 0xf4268:
    (**(code **)(**(int **)(in_ECX + 0x238) + 0xd4))();
    (**(code **)(**(int **)(in_ECX + 0x234) + 0xd4))();
    *(undefined1 *)(in_ECX + 0x230) = 0;
    return;
  case 0xf4269:
    FUN_005ad270(in_ECX);
    return;
  case 0xf426a:
    FUN_005ad1e0(in_ECX);
    return;
  case 0xf42ad:
    FUN_005ad9f0(param_1);
    return;
  case 0xf42ae:
    FUN_005adb70();
    return;
  case 0xf42af:
    FUN_005adbe0();
  }
  return;
}

