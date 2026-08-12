#include <quickjs.h>
#include <stdio.h>

int main(void)
{
    JSRuntime* rt = JS_NewRuntime();
    JSContext* ctx = JS_NewContext(rt);

    JSValue val = JS_Eval(
        ctx,
        "1 + 2",
        5,
        "<input>",
        JS_EVAL_TYPE_GLOBAL
    );

    int result;
    JS_ToInt32(ctx, &result, val);

    printf("%d\n", result);

    JS_FreeValue(ctx, val);
    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);

    return 0;
}
