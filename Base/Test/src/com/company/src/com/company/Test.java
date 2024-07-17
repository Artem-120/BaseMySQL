package com.company.src.com.company;

import org.junit.Test;

import java.lang.annotation.Retention;
import java.lang.annotation.Target;
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

import static java.lang.annotation.ElementType.METHOD;
import static java.lang.annotation.ElementType.TYPE;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;


@Retention(java.lang.annotation.RetentionPolicy.RUNTIME)
@Target({METHOD, TYPE})
@interface Selector {

    String xpath();
}

class MethodInterception {

    @Test
    public void annotationValue() {
        MainPage mainPage = createPage(MainPage.class);

        assertNotNull(mainPage);
        assertEquals(mainPage.buttonSearch(), ".//*[@test-attr='button_search']");
        assertEquals(mainPage.textInputSearch(), ".//*[@test-attr='input_search']");
    }

    private static MainPage createPage(Class<MainPage> clazz) {
        return (MainPage)Proxy.newProxyInstance(SomeInvocationHandler.class.getClassLoader(), new Class[] { clazz },
                new SomeInvocationHandler());
    }

}

interface MainPage {

    @Selector(xpath = ".//*[@test-attr='input_search']")
    String textInputSearch();

    @Selector(xpath = ".//*[@test-attr='button_search']")
    String buttonSearch();
}


class SomeInvocationHandler implements InvocationHandler {

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
       return method.getAnnotation(Selector.class).xpath();
    }
}

